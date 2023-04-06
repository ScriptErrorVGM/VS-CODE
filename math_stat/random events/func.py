from math import factorial


def c_w_r(n,r):
    return ((factorial(n + r - 1)) / (factorial(r) * (factorial(n-1))))

def c_no_r(n,r):
    return (factorial(n) / (factorial(r) * (factorial(n-r))))

def p_no_r(n,r):
    return (factorial(n) / (factorial(n-r)))

def p_w_r(n,r):
    return n**r

def p_A(m,n):
    return m/n

def print_P(m,n,L):
    print('P(',L,') = ', m,'/',n, ' = ', p_A(m,n))

def bayes_form(P_h,P_a_h,sum_p):
    return (P_h*P_a_h)/sum_p