# Use a base image (e.g., Ubuntu)
FROM ubuntu:20.04

# Set non-interactive mode for apt-get
ENV DEBIAN_FRONTEND=noninteractive

# Install basic utilities
RUN apt-get update && apt-get install -y \
    sudo \
    man-db \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create a user 'user' with a password
RUN useradd -ms /bin/bash user && echo "user:12345678" | chpasswd

# Set permissions
RUN chown -R user:user /home/user

USER user
WORKDIR /home/user

# Start a shell when the container starts
CMD ["/bin/bash"]
