# Use the official Ubuntu base image
FROM ubuntu:20.04

# Set non-interactive frontend to avoid any interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages including sudo
RUN apt-get update && apt-get install -y \
    gcc \
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
    sudo \
    cron \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create user artemis
RUN useradd -ms /bin/bash artemis && echo "artemis:diana" | chpasswd
RUN chown -R artemis:artemis /home/artemis
# Add the artemis user to the sudo group to grant sudo privileges
RUN usermod -aG sudo artemis

# Create necessary directories
RUN mkdir -p /home/artemis/AssortedFlags
RUN mkdir -p /home/artemis/BasicPipingAndRedirection

# Copy the C files, shell script, and the MegaFile into the BasicPipingAndRedirection folder
COPY ./pipe.c /home/artemis/BasicPipingAndRedirection/pipe.c
COPY ./BinaryChecker.c /home/artemis/BasicPipingAndRedirection/binarychecker.c
COPY ./generate_flags.sh /home/artemis/generate_flags.sh
RUN echo "hello_mega_file" > /home/artemis/BasicPipingAndRedirection/MegaFile

# Set executable permission for the script and run it
RUN chmod +x /home/artemis/generate_flags.sh && /home/artemis/generate_flags.sh && rm /home/artemis/generate_flags.sh

# Compile C programs inside the BasicPipingAndRedirection folder
RUN gcc /home/artemis/BasicPipingAndRedirection/pipe.c -o /home/artemis/BasicPipingAndRedirection/pipe
RUN gcc /home/artemis/BasicPipingAndRedirection/binarychecker.c -o /home/artemis/BasicPipingAndRedirection/binarychecker

# Remove C source files after compilation
RUN rm -rf /home/artemis/BasicPipingAndRedirection/pipe.c /home/artemis/BasicPipingAndRedirection/binarychecker.c

# Switch to the artemis user
USER artemis

# Set working directory to artemis's home directory
WORKDIR /home/artemis

# Default command to run a bash shell
CMD ["/bin/bash"]
