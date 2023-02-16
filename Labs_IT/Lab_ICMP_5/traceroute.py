import sys
import os
import socket
import time
import struct
import select

#ICMP ECHO ЗАПРОС (для возможности проводить traceroute)
ICMP_ECHO_REQUEST = 8

#УСТАНОВКА ТАЙМАУТА (В СЕКУНДАХ)
TIMEOUT = int(input("Введите время ожидания для каждого запроса: "))

#УСТАНОВКА МАКСИМАЛЬНОГО КОЛИЧЕСТВА ПРЫЖКОВ
MAX_HOPS = int(input("Введите максимальное число прыжков (по умолчанию 30): "))

#Подсчёт контрольной суммы
def calc_checksum(header):
    checksum = 0
    overflow = 0

    for i in range(0, len(header), 2):
        word = header[i] + (header[i+1] << 8)

        checksum = checksum + word
        overflow = checksum >> 16
        while overflow > 0:
            checksum = checksum & 0xFFFF
            checksum = checksum + overflow
            overflow = checksum >> 16

    overflow = checksum >> 16
    while overflow > 0:
        checksum = checksum & 0xFFFF
        checksum = checksum + overflow
        overflow = checksum >> 16

    checksum = ~checksum
    checksum = checksum & 0xFFFF

    return checksum



#Функция "Пинг"
def ping(dest_addr, icmp_socket, time_to_live, id):
    #Присваивание контрольной сумме начальное значение 0 и создания массива, содержащее данные для выполнения пинга
    initial_checksum = 0
    initial_header = struct.pack("bbHHh",
                                 ICMP_ECHO_REQUEST,
                                 0,
                                 initial_checksum,
                                 id,
                                 1)

    #Актуальная контрольная сумма и актуальные данные пинга
    calculated_checksum = calc_checksum(initial_header)
    header = struct.pack("bbHHh",
                         ICMP_ECHO_REQUEST,
                         0,
                         calculated_checksum,
                         id,
                         1)

    #Установка опций сокета
    icmp_socket.setsockopt(socket.IPPROTO_IP, socket.IP_TTL, time_to_live)

    #Отправка пакета
    icmp_socket.sendto(header, (dest_addr, 1))

    #Получение времени для ожидания ответа
    start_time = time.time()

    #Таймаут
    socketResponseReady = select.select([icmp_socket], [], [], TIMEOUT)
    if socketResponseReady[0] == []:
        print('{0}\t{1} мс\t*\t(Таймаут)'.
              format(time_to_live,
                     int((time.time() - start_time) * 1000.00)))
        return False

    #Получение данных от сокета
    recv_packet, addr = icmp_socket.recvfrom(1024)
    hostname = ''
    try:
        #Попытка конвертации IP-адреса в имя хоста
        host_details = socket.gethostbyaddr(addr[0])
        if len(host_details) > 0:
            hostname = host_details[0]
    except:
        #В случае, если у айпи адреса нет имени, то будет выводится данное сообщение
        hostname = 'неизвестное имя хоста'

    #Вывод времени {1}, которое было затрачено на получение ответа.
    #Отображение порядкого номера узла {0}, его IP-адреса {2}, а так же имя хоста {3}.
    print('{0}\t{1} мс\t{2}\t{3}'.
          format(time_to_live,
                 int((time.time() - start_time) * 1000.00),
                 addr[0],
                 hostname))

    #Если пакет был успешно доставлен и был получен ответ возвращаем True
    if addr[0] == dest_addr:
        return True

    #Если ответ не был получен или пакет не был доставлен возвращаем False
    return False

def main():
    #Ввод адреса и его преобразование в IP (или же имя хоста)
    dest_host = input("Введите адрес: ")
    dest_addr = socket.gethostbyname(dest_host)

    print("Путь к {1} ({0}) при максимальном количестве прыжков {2}".
          format(dest_addr,
                 dest_host,
                 MAX_HOPS))

    #Установка начального значения TTL
    time_to_live = 1
    id = 1
    while(time_to_live < MAX_HOPS):
        #Создание ICMP протокола
        icmp_proto = socket.getprotobyname("icmp")
        try:
            #Создание сокета
            icmp_socket = socket.socket(socket.AF_INET,
                                        socket.SOCK_RAW,
                                        icmp_proto)
        except socket.error as exception:
            #Получение ошибки
            print("АШИБКА " + exception)
            os._exit(1)

		#Это для того, чтобы программа вечно не искала путь, а завершалась при достижение финальной точки.
        if(ping(dest_addr, icmp_socket, time_to_live, id)):
            icmp_socket.close()
            break

        #Если ping возвращает False, то происходит увелечение TTL на единицу и
        #запускает действие по новой, до тех пор пока не дойдёт до контрольной точки
        time_to_live += 1
        id += 1
        icmp_socket.close()

    #Завершение программы
    os._exit(0)


#Запуск программы
if __name__ == "__main__":
    main()
