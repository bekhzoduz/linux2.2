#!/bin/bash

# AssortedFlags papkasini yaratish agar mavjud bo'lmasa
mkdir -p /home/artemis/AssortedFlags

# To'g'ri bayroqning prefiksi
correct="00c4970c"

# 30 ta fayl yaratish
for i in {1..30}; do
    # Har bir fayl uchun tasodifiy 8-ramkali hex string yaratish
    hex=$(openssl rand -hex 4)  # 4 bayt = 8 hex belgisi

    # Agar to'g'ri bayroq bo'lsa, fayl nomi quyidagicha bo'ladi
    if [ $i -eq 1 ]; then
        file_name="OS{${correct}_what_an_asSORTment_of_flags}"
        echo "$correct" > /home/artemis/AssortedFlags/$file_name
    else
        # Aks holda, xato fayl nomi quyidagicha bo'ladi (qavslar yo'q)
        file_name="OS{${hex}_what_an_asSORTment_of_flags}"
        touch /home/artemis/AssortedFlags/$file_name
    fi
done

echo "Flags generated successfully."
