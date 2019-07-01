using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConvertNumber
{
    public class ConvertNumber
    {
        private const uint MIN_ROMAN_NUMBER = 1;
        private const uint MAX_ROMAN_NUMBER = 3999;

        private static Dictionary<int, string> decimalAndRomanList = new Dictionary<int, string>()
        {
            { 1000, "M" },
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "IX" },
            { 5, "V" },
            { 4, "IV" },
            { 1, "I" }
        };

        public static string ConvertToRoman(int number)
        {
            if (number < MIN_ROMAN_NUMBER || number > MAX_ROMAN_NUMBER)
            {
                throw new ArgumentOutOfRangeException("number", number, $"Value must be between {MIN_ROMAN_NUMBER} and {MAX_ROMAN_NUMBER}.");
            }

            int valueToSubtract = number;
            StringBuilder romanNumber = new StringBuilder();

            foreach (var entry in decimalAndRomanList)
            {
                var currentDecimalValue = entry.Key;
                var currentRomanValue = entry.Value;

                while (valueToSubtract >= currentDecimalValue)
                {
                    romanNumber.Append(currentRomanValue);
                    valueToSubtract -= currentDecimalValue;
                }
                if (valueToSubtract == 0)
                {
                    break;
                }
            }
            
            return romanNumber.ToString();
        }
    }
}
