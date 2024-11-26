FROM ubuntu:20.04

# Set non-interactive frontend for apt to avoid prompts during build
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages in a single RUN step to minimize layers
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
    grep \
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

# Create user 'hermes' and set password
RUN useradd -ms /bin/bash hermes && echo "hermes:mercury" | chpasswd

# Copy C source files to the user's home directory
COPY ./check_file_create.c /home/hermes/check_file_create.c
COPY ./check_directory_delete.c /home/hermes/check_directory_delete.c


# Compile C programs
RUN gcc /home/hermes/check_file_create.c -o /home/hermes/check_file_create \
    && gcc /home/hermes/check_directory_delete.c -o /home/hermes/check_directory_delete 

# Remove source files after compilation
RUN rm /home/hermes/check_file_create.c /home/hermes/check_directory_delete.c

# Create necessary directories and files
RUN mkdir -p /home/hermes/FullOfStuff \
    && mkdir -p /var/www/slippers \
    && touch /var/www/slippers/qanotlar


RUN ln -s /var/www/slippers/qanotlar /home/hermes/qanotlar_symlink 

# Set permissions for the home directory and other important directories
RUN chown -R hermes:hermes /home/hermes /var/www/slippers

# Switch to the 'hermes' user
USER hermes
WORKDIR /home/hermes

CMD ["/bin/bash"]
