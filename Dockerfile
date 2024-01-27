# Use an official C++ image as a base image
FROM rikorose/gcc-cmake:latest

# Set the working directory inside the container
WORKDIR /usr/app

# Copy the content of your local source directory to the working directory
COPY . .

RUN apt-get update && apt-get install -y \
    libgtest-dev \
    && git clone https://github.com/catchorg/Catch2.git \
    && cd Catch2 \
    && cmake -Bbuild -H. -DBUILD_TESTING=OFF \
    && cmake --build build/ --target install \
    && cd .. 

# Run CMake to generate build files
RUN cmake .

# Compile your C++ code
RUN make

CMD ["ctest"]