package romannumber

import (
	"bytes"
)

// IntRoman : Base type to convert to roman number
type IntRoman int

type romanNumber struct {
	decimalValue int
	romanValue   string
}

var romanValues = []romanNumber{
	{1000, "M"},
	{900, "CM"},
	{500, "D"},
	{400, "CD"},
	{100, "C"},
	{90, "XC"},
	{50, "L"},
	{40, "XL"},
	{10, "X"},
	{9, "IX"},
	{5, "V"},
	{4, "IV"},
	{1, "I"},
}

// ToRoman : Convert a value to roman format
func (number *IntRoman) ToRoman() string {
	valueSubtract := int(*number)
	var buffer bytes.Buffer

	for _, item := range romanValues {
		currentDecimalValue := item.decimalValue
		currentRomanValue := item.romanValue

		for ; valueSubtract >= currentDecimalValue; valueSubtract -= currentDecimalValue {
			buffer.WriteString(currentRomanValue)
		}
		if valueSubtract == 0 {
			break
		}
	}

	return buffer.String()
}
