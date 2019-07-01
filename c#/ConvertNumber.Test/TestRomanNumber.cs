using System;
using System.Data;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ConvertNumber
{
    [TestClass]
    public class TestRomanNumber
    {
        private TestContext testContextInstance;
        public TestContext TestContext
        {
            get { return testContextInstance; }
            set { testContextInstance = value; }
        }
        
        [TestMethod]
        [DataSource("Microsoft.VisualStudio.TestTools.DataSource.XML",
                    "|DataDirectory|\\TestRomanNumber.xml",
                    "Row",
                    DataAccessMethod.Sequential)]
        public void TestValueFromXML()
        {
            int numberToTest = int.Parse(TestContext.DataRow["DecimalNumber"] as string);
            string expectedRomanNumber = TestContext.DataRow["RomanNumber"] as string;

            string actualRomanNumber = ConvertNumber.ConvertToRoman(numberToTest);
            Assert.AreEqual<string>(expectedRomanNumber, actualRomanNumber);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException), "Any value lower than '1' should generate 'ArgumentOutOfRangeException'.")]
        public void TestLowerThanMinValue()
        {
            ConvertNumber.ConvertToRoman(0);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException), "Any value higher than '3999' should generate 'ArgumentOutOfRangeException'.")]
        public void TestHigherThanMaxValue()
        {
            ConvertNumber.ConvertToRoman(4000);
        }
    }
}
