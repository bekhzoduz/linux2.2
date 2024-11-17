# Asosiy tasvir sifatida Ubuntu 20.04 dan foydalanamiz
FROM ubuntu:20.04

# Interaktiv emasligini belgilaymiz (apt-get uchun)
ENV DEBIAN_FRONTEND=noninteractive

# Zaruriy dasturlarni o'rnatamiz
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
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Artemis foydalanuvchisini yaratamiz va unga parol o'rnatamiz
RUN useradd -ms /bin/bash artemis \
    && echo "artemis:diana" | chpasswd

# Zarur C faylni konteynerga ko'chiramiz va kompilyatsiya qilamiz
COPY ./2.8.1.1.c /home/artemis/
RUN gcc /home/artemis/2.8.1.1.c -o /home/artemis/hello \
    && rm -rf /home/artemis/2.8.1.1.c

# Ishchi katalogni sozlaymiz
WORKDIR /home/artemis

# Artemis foydalanuvchisi bilan ishlaymiz
USER artemis

# Konteyner ishga tushganda bash interfeysini ochamiz
CMD ["/bin/bash"]
