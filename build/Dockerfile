FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
	&& apt-get install -y \
		# build deps
		clang \
		make \
		# criterion deps
		wget \
		tar \
		xz-utils \
		# X11 deps
		libx11-dev \
		libxext-dev \
		x11-apps \
		# test deps
		valgrind \
	&& rm -rf /var/lib/apt/lists/

RUN wget https://github.com/Snaipe/Criterion/releases/download/v2.4.2/criterion-2.4.2-linux-x86_64.tar.xz \
	&& tar -xvf criterion-2.4.2-linux-x86_64.tar.xz \
	&& cp -r criterion-2.4.2/lib/* /usr/lib \
	&& cp -r criterion-2.4.2/include/* /usr/include \
	&& rm -rf criterion-2.4.2-linux-x86_64.tar.xz \
	&& rm -rf criterion-2.4.2

WORKDIR /app