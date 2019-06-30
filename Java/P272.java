import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.*;
import java.util.*;

/**
 * P272
 */
class P272 {

    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }

    public static void main (String args[])  // entry point from OS
    {
        Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point
    }

    void Begin()
    {
        String input;
        StringTokenizer idata;
        int a, b, min, max, num, n, cycle, cyclemax;

        while ((input = Main.ReadLn (255)) != null)
        {
            
            String output = input;
            int par = 0;
            Matcher quotes = Pattern.compile("\"").matcher(output);
            while(quotes.find()) {
                if(par%2==0) {
                    output = output.replaceFirst(quotes.group(), "``");
                } else {
                    output = output.replaceFirst(quotes.group(), "\'\'");
                }
                par++;
            }
            System.out.println(output);
        }
    }



}

