# Ubuntu 20.04 asosida imidjdan boshlash
FROM ubuntu:20.04

# Interaktiv bo'lmagan rejimda ishlash
ENV DEBIAN_FRONTEND=noninteractive

# Kerakli paketlarni o'rnatish
RUN apt-get update && apt-get install -y \
    rsync \
    curl \
    libc6 \
    vim \
    git \
    htop \
    net-tools \
    tar \
    openssl \
    man-db \
    build-essential \
    software-properties-common \
    wget \
    unzip \
    lsb-release \
    ca-certificates \
    gcc \
    sudo \
    cron \
    mlocate \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Foydalanuvchi 'haad'ni yaratish va unga parol o'rnatish
RUN useradd -ms /bin/bash haad && echo "haad:haad" | chpasswd

# Fayllarni kerakli joyga nusxalash
COPY ./pmgg.sh /home/haad/pmgg.sh
COPY ./xcalc.c /var/www/xcalc.c

# pmgg.c faylini kompilyatsiya qilish va pmgg bajariladigan faylini yaratish
RUN gcc /var/www/xcalc.c -o /var/www/xcalc

# pmgg.c faylini o'chirish
RUN rm -f /var/www/xcalc.c

# lostflag.txt faylini /usr/tmp/lost papkasida yaratish
RUN mkdir -p /usr/tmp/lost && \
    echo "HD{meni_topganingizdan_juda_xursandman}" > /usr/tmp/lost/lostflag.txt

# pmgg faylini bajarish ruxsatlarini berish
RUN chmod +x /var/www/xcalc

# Foydalanuvchi 'haad'ga o'zgartirish
USER haad
WORKDIR /home/haad

# locate va updatedb uchun kerakli papkalarni yaratish
USER root
RUN mkdir -p /var/lib/mlocate && \
    updatedb

# CMD qismida bash ishga tushadi
CMD ["/bin/bash"]
