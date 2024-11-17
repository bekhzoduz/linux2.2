FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gcc \
    gdb \
    vim \
    man-db \
    manpages \
    && rm -rf /var/lib/apt/lists/*

RUN yes | unminimize

RUN mkdir -p /home/atlas/helpman /home/atlas/panmages

COPY ./helpme.c /home/atlas/helpman/helpme.c
RUN gcc /home/atlas/helpman/helpme.c -o /home/atlas/helpman/helpme

COPY ./panmages.c /home/atlas/panmages/
RUN gcc /home/atlas/panmages/panmages.c -o /home/atlas/panmages/panmages

RUN rm -rf /home/atlas/panmages/panmages.c 

COPY panmages.1.gz /usr/share/man/man1/

RUN mandb

COPY ./game-guide.txt /home/atlas/panmages/game-guide.txt

RUN useradd -m -d /home/atlas -s /bin/bash atlas \
    && echo "atlas:atlas" | chpasswd

RUN chown -R atlas:atlas /home/atlas*
USER atlas
WORKDIR /home/atlas

CMD ["/bin/bash"]
