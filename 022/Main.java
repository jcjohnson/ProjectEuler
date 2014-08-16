import java.util.*;
import java.io.*;

public class Main
{

    public static void main(String[] args) throws IOException {
        System.out.println("Value of COLIN is " + getValue("COLIN"));
        Scanner sc = new Scanner(new File("names.txt"));
        sc.useDelimiter("\\Q.++\\E");
        Set<String> names = new TreeSet<String>();
        while(sc.hasNext()) {
            StringTokenizer st = new StringTokenizer(sc.next(), "\",");
            while(st.hasMoreTokens()) {
                names.add(st.nextToken());
            }
        }
        int sum = 0;
        int index = 1;
        for(String s: names) {
            System.out.println(index + ": " + s);
            sum += index * getValue(s);
            index++;
        }
        System.out.println(sum);
    }

    public static int getValue(String s) {
        int value = 0;
        for(int i=0; i<s.length(); i++) {
            value += s.charAt(i) - 'A' + 1;
        }
        return value;
    }

}
