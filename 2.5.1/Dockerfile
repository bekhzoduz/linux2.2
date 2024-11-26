# Use a base image (e.g., Ubuntu)
FROM ubuntu:20.04

# Set non-interactive mode for apt-get
ENV DEBIAN_FRONTEND=noninteractive

# Install basic utilities and SSH
RUN apt-get update && apt-get install -y \
    rsync \
    curl \
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
    openssh-server \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create necessary SSH host keys
RUN mkdir -p /etc/ssh && ssh-keygen -A

# Create users and set passwords
RUN useradd -ms /bin/bash atlas && echo "atlas:titan" | chpasswd && \
    useradd -ms /bin/bash eris && echo "eris:discordia" | chpasswd && \
    useradd -ms /bin/bash Admin && echo "Admin:Admin" | chpasswd && \
    usermod -aG sudo Admin

RUN echo "export flag=HD{qanday-GLOBAL-sensatsiya!}" >> /home/atlas/.bashrc

WORKDIR /home/eris

COPY ./checkpath.c ./checkls.c ./
RUN gcc checkpath.c -o checkpath && rm -f checkpath.c && \
    gcc checkls.c -o checkls && rm -f checkls.c


RUN echo 'alias ls="echo \"ls buyrug‘i ishlamaydi!\""' >> /home/eris/.bashrc
RUN echo 'export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/proc' >> /home/eris/.bashrc
RUN echo 'alias showflag="echo '\''Flag: HD{Hech_narsa_etiboringdan_tashqarida_emas}'\''"' >> /home/eris/.bashrc

WORKDIR /home/atlas

COPY ./history.c ./
RUN gcc history.c -o history && rm -f history.c

RUN echo 'alias history="/home/atlas/history"' >> /home/atlas/.bashrc

# Set permissions for user directories
RUN chown -R atlas:atlas /home/atlas && chmod 700 /home/atlas && \
    chown -R eris:eris /home/eris && chmod 700 /home/eris

# Switch to Admin user for final setup
USER Admin
WORKDIR /home/Admin

# Expose the SSH port
EXPOSE 22

# Start the SSH service and keep the container running
CMD ["/usr/sbin/sshd", "-D"]