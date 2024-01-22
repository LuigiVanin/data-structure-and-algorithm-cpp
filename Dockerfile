# Use an official C++ image as a base image
FROM rikorose/gcc-cmake:latest

# Set the working directory inside the container
WORKDIR /usr/src/app

# Copy the content of your local source directory to the working directory
COPY . .

# Run CMake to generate build files
RUN cmake .

# Compile your C++ code
RUN make

CMD ["ctest"]