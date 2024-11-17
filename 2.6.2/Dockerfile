# Use a basic image with bash support
FROM ubuntu:20.04

# Install necessary tools and compilers
RUN apt-get update && apt-get install -y \
    bash \
    sudo \
    coreutils \
    findutils \
    file \
    wget \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Create the user 'athena' with password 'minerva' and add to sudo group
RUN useradd -m -s /bin/bash athena && \
    echo "athena:minerva" | chpasswd && \
    usermod -aG sudo athena

# Set the home directory for athena user
WORKDIR /home/athena

# Task 1: Create the 'ManyFiles' directory and fill it with 6 empty files containing the letter "g" in the filename
RUN mkdir -p /home/athena/ManyFiles && \
    bash -c 'g_words=("apple" "dog" "garden" "orange" "table" "balloon" "train" "house" "mountain" "flower" "guitar" "river" "book" "pen" "computer" "happy" "purple" "cat" "football" "street" "school" "window" "ocean" "kitchen" "clock" "phone" "paper" "star" "elephant" "fish" "sweater" "cookie" "tree" "bed" "rain" "ship" "road" "chair" "laptop" "dream" "key" "ice" "red" "bookcase" "blue" "coat" "sky" "ball" "flowerpot" "door" "walk" "sky" "snow" "lenovo" "puzzle" "candle" "cloud" "internet" "cloud" "green" "test" "sky" "jacket" "egg" "puzzle") && \
    for word in "${g_words[@]}"; do \
        touch /home/athena/ManyFiles/$word.txt; \
    done && \
    # Make sure files are empty and have the same size
    find /home/athena/ManyFiles -type f -exec truncate -s 0 {} \;'

# Task 2: Create the 'MoreFiles' directory, fill it with 100 random files (random names and types), and create '/MoreFiles/Athena Documents'
RUN mkdir -p /home/athena/MoreFiles && \
    mkdir -p "/home/athena/MoreFiles/Athena Documents" && \
    bash -c 'words=("apple" "peach" "banana" "grape" "kiwi" "orange" "melon" "cherry" "plum" "apricot" "watermelon" "blueberry") && \
    types=("txt" "pdf" "png" "html" "docx" "xml") && \
    for i in $(seq 1 100); do \
        word="${words[$((RANDOM % ${#words[@]}))]}" && \
        type="${types[$((RANDOM % ${#types[@]}))]}" && \
        touch /home/athena/MoreFiles/$word.$type; \
    done'

# Task 3: Create the 'MassiveFiles' directory and fill it with 100 random files (random names and types)
RUN mkdir -p /home/athena/MassiveFiles && \
    bash -c 'words=("computer" "phone" "keyboard" "mouse" "monitor" "speaker" "tablet" "headphones" "camera" "printer" "scanner" "flashdrive") && \
    types=("txt" "pdf" "png" "html" "docx" "xml") && \
    for i in $(seq 1 100); do \
        word="${words[$((RANDOM % ${#words[@]}))]}" && \
        type="${types[$((RANDOM % ${#types[@]}))]}" && \
        touch /home/athena/MassiveFiles/$word.$type; \
    done'

# Add the C code for the check files
COPY check_more_files.c /home/athena/check_more_files.c
COPY check_massive_files.c /home/athena/check_massive_files.c

# Compile the C files
RUN gcc /home/athena/check_more_files.c -o /home/athena/check_more_files
RUN gcc /home/athena/check_massive_files.c -o /home/athena/check_massive_files

# Remove the C source files
RUN rm /home/athena/check_more_files.c
RUN rm /home/athena/check_massive_files.c

# Add the binary check files for flag retrieval
RUN chmod +x /home/athena/check_more_files
RUN chmod +x /home/athena/check_massive_files

# Set the default command
CMD ["/bin/bash"]
