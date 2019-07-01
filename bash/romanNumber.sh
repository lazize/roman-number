romanNumber()
{
    local VALUE_TO_DIVIDE_AND_SUBTRACT="${1}"
    
    local readonly MIN_ROMAN_NUMBER=1
    local readonly MAX_ROMAN_NUMBER=3999
    local readonly DECIMAL_VALUES=( 1000 900  500 400  100 90   50  40   10  9    5   4    1 )
    local readonly ROMAN_VALUES=(   "M"  "CM" "D" "CD" "C" "XC" "L" "XL" "X" "IX" "V" "IV" "I" )

    if [[ "${VALUE_TO_DIVIDE_AND_SUBTRACT}" -lt "${MIN_ROMAN_NUMBER}" || "${VALUE_TO_DIVIDE_AND_SUBTRACT}" -gt "${MAX_ROMAN_NUMBER}" ]]
    then
        echo "Value must be between ${MIN_ROMAN_NUMBER} and ${MAX_ROMAN_NUMBER}." >&2
        return 1
    fi

    local ROMAN_NUMBER=""
    local INDEX=0

    for ((INDEX=0; INDEX < ${#DECIMAL_VALUES[@]}; INDEX++))
    do
        local readonly CURRENT_DECIMAL_VALUE="${DECIMAL_VALUES[INDEX]}"
        local readonly CURRENT_ROMAN_VALUE="${ROMAN_VALUES[INDEX]}"

        if [[ "${VALUE_TO_DIVIDE_AND_SUBTRACT}" -ge "${CURRENT_DECIMAL_VALUE}" ]]
        then
            local readonly AMOUNT_OF_DECIMAL_VALUE=$((${VALUE_TO_DIVIDE_AND_SUBTRACT} / ${CURRENT_DECIMAL_VALUE}))
            
            local readonly COUNT=0
            for ((COUNT=0; COUNT < ${AMOUNT_OF_DECIMAL_VALUE}; COUNT++))
            do
                ROMAN_NUMBER="${ROMAN_NUMBER}${CURRENT_ROMAN_VALUE}"
            done
            
            VALUE_TO_DIVIDE_AND_SUBTRACT=$(( ${VALUE_TO_DIVIDE_AND_SUBTRACT} - (${CURRENT_DECIMAL_VALUE} * ${AMOUNT_OF_DECIMAL_VALUE} ) ))
            if [[ "${VALUE_TO_DIVIDE_AND_SUBTRACT}" -eq 0 ]]
            then
                break
            fi
        fi
    done
    
    echo "${ROMAN_NUMBER}"
    return 0
}

romanNumber 0
romanNumber 1
romanNumber 4
romanNumber 5
romanNumber 7
romanNumber 9
romanNumber 10
romanNumber 90
romanNumber 99
romanNumber 899
romanNumber 3999
romanNumber 4000
