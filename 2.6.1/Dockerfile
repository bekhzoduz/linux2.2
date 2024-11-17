# Use a base image (e.g., Ubuntu)
FROM ubuntu:20.04

# Set non-interactive mode for apt-get
ENV DEBIAN_FRONTEND=noninteractive

# Install basic utilities and dependencies for compiling C programs
RUN apt-get update && apt-get install -y \
    sudo \
    man-db \
    gcc \
    make \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create user 'hermes' with password 'mercury'
RUN useradd -ms /bin/bash hermes && echo "hermes:mercury" | chpasswd

# Create home directory for hermes user
RUN mkdir -p /home/hermes

# Copy the C files for check_file_create and check_directory_delete
COPY ./check_file_create.c /home/hermes/check_file_create.c
COPY ./check_directory_delete.c /home/hermes/check_directory_delete.c

# Compile the C programs
RUN gcc /home/hermes/check_file_create.c -o /home/hermes/check_file_create
RUN gcc /home/hermes/check_directory_delete.c -o /home/hermes/check_directory_delete

# Remove the C source files
RUN rm /home/hermes/check_file_create.c
RUN rm /home/hermes/check_directory_delete.c

# Create the necessary files and directories
RUN mkdir -p /home/hermes/FullOfStuff
RUN touch /home/hermes/fast.txt

# Set permissions for the home directory
RUN chown -R hermes:hermes /home/hermes

# Switch to the user 'hermes'
USER hermes
WORKDIR /home/hermes

# Start an interactive bash shell
ENTRYPOINT ["/bin/bash"]
