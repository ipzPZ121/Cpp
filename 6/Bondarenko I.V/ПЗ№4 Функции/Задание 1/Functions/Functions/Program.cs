using System;


namespace Functions
{
    class StrComp
    {
        static public int Srch(ref string str1, ref string str2)
        {
            return str1.CompareTo(str2);
        }
    }

    class Program
    {
        

        static void Main(string[] args)
        {
            string strA = "aaaaaaa";
            string strB = "qewqrwd";

            Console.WriteLine(StrComp.Srch(ref strA, ref strB));

        }
    }
}
