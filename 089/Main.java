import java.io.*;
import java.util.*;

public class Main {

  public static Map<Character, Integer> charToValue = new HashMap<Character, Integer>();
  public static final Map<Integer, String> ONES = makeDigitMap("I", "V", "X");
  public static final Map<Integer, String> TENS = makeDigitMap("X", "L", "C");
  public static final Map<Integer, String> HUNDREDS = makeDigitMap("C", "D", "M");
  public static final String THOUSAND = "M";

  static {
    charToValue.put('I', 1);
    charToValue.put('V', 5);
    charToValue.put('X', 10);
    charToValue.put('L', 50);
    charToValue.put('C', 100);
    charToValue.put('D', 500);
    charToValue.put('M', 1000);
  }

  public static Map<Integer, String> makeDigitMap(String one, String five, String ten) {
    Map<Integer, String> m = new HashMap<Integer, String>();
    m.put(0, "");
    m.put(1, one);
    m.put(2, one + one);
    m.put(3, one + one + one);
    m.put(4, one + five);
    m.put(5, five);
    m.put(6, five + one);
    m.put(7, five + one + one);
    m.put(8, five + one + one + one);
    m.put(9, one + ten);
    return m;
  }

  public static void main(String[] args) throws IOException {
    if (args.length < 1) {
      System.err.println("USAGE: Main filename");
      System.exit(1);
    }

    String filename = args[0];
    Scanner sc = new Scanner(new File(filename));
    
    int numCharactersSaved = 0;
    while (sc.hasNextLine()) {
      String romanNumerals = sc.nextLine();
      int value = parseRomanNumerals(romanNumerals);
      String bestRomanNumerals = encodeRomanNumerals(value);
      int numSaved = romanNumerals.length() - bestRomanNumerals.length();
      System.out.println(romanNumerals + " = " + value + " = " + bestRomanNumerals + ", " + numSaved);
      numCharactersSaved += numSaved; 
    }
    System.out.println(numCharactersSaved);
  }

  public static int parseRomanNumerals(String romanNumerals) {
    int value = 0;
    for (int i = 0; i < romanNumerals.length(); i++) {
      int curValue = charToValue.get(romanNumerals.charAt(i));
      if (i + 1 < romanNumerals.length()) {
        int nextValue = charToValue.get(romanNumerals.charAt(i + 1));
        if (curValue < nextValue) {
          value += nextValue - curValue;
          i++;
          continue;
        }
      }
      value += curValue;
    }
    return value;
  }

  public static String encodeRomanNumerals(int value) {
    StringBuilder sb = new StringBuilder();
    while (value >= 1000) {
      sb.append(THOUSAND);
      value -= 1000;
    }

    sb.append(HUNDREDS.get(value / 100));
    value %= 100;

    sb.append(TENS.get(value / 10));
    value %= 10;

    sb.append(ONES.get(value));

    return sb.toString();
  }

}
