#!/bin/bash

# AssortedFlags papkasini yaratish agar mavjud bo'lmasa
mkdir -p /home/artemis/AssortedFlags

# Create output file
output_file="/home/artemis/AssortedFlags/pile_of_flags.txt"

# To'g'ri bayroqning prefiksi
correct="00c4970c"

# Convert the correct flag to a decimal number for comparison
correct_decimal=$((16#$correct))

# 100 ta flag yaratish
for i in {1..100}; do
    # Har bir flag uchun tasodifiy 8-ramkali hex string yaratish
    hex=$(openssl rand -hex 4)  # 4 bayt = 8 hex belgisi

    # Convert generated hex to decimal for comparison
    hex_decimal=$((16#$hex))
    
    # Agar to'g'ri bayroq bo'lsa
    if [ $i -eq $((RANDOM % 10 + 1)) ]; then
        flag_name="HD{${correct}_qanday_ajoyib_flaglar_jamlanmasi}"
        echo -e "$flag_name" >> "$output_file"
    else
        # Ensure the generated hex is larger than the correct flag
        while [ $hex_decimal -le $correct_decimal ]; do
            # Regenerate the hex if it's smaller than or equal to the correct flag
            hex=$(openssl rand -hex 4)
            hex_decimal=$((16#$hex))
        done
        # Aks holda, xato flag nomi
        flag_name="HD{${hex}_qanday_ajoyib_flaglar_jamlanmasi}"
        echo -e "$flag_name" >> "$output_file"
    fi
done

echo "Flags written to pile_of_flags.txt successfully."
