package romannumber_test

import (
	"romannumber"
	"testing"
)

func TestValue98(t *testing.T) {
	const shouldBe = "XCVIII"
	const numberToConvert = 98

	romanInt := romannumber.IntRoman(numberToConvert)
	asIs := romanInt.ToRoman()
	if shouldBe != asIs {
		t.Error("For:", numberToConvert, "Expected:", shouldBe, "Result:", asIs)
	}
}
func TestRomanTable(t *testing.T) {
	var romanTest = map[string]int{
		"I":        1,
		"X":        10,
		"C":        100,
		"M":        1000,
		"DCCCXCIX": 899,
		"XC":       90,
		"IX":       9,
		"IV":       4,
		"XL":       40,
		"III":      3,
		"XCIX":     99,
	}

	for shouldBe, numberToConvert := range romanTest {
		romanInt := romannumber.IntRoman(numberToConvert)
		asIs := romanInt.ToRoman()
		if shouldBe != asIs {
			t.Error("For:", numberToConvert, "Expected:", shouldBe, "Result:", asIs)
		}
	}
}
