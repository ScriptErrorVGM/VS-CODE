import java.util.regex.*;
public class Correct_func {
    
    static boolean isCorrect(String str){
        
        String regex =("[А-Яа-я]*\\s[А-Яа-я]*\\s[А-Яа-я]*(0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20)\\d\\d*\\s");
        Pattern patrn = Pattern.compile(regex);

        String[] ss = str.split(",");
        for (String s: ss){
            
        }
    }
    
}
