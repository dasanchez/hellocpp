FROM gcc:10

RUN apt-get -qq update
RUN apt-get -qq upgrade
# RUN apt-get -qq install gfortran
RUN dpkg --configure -a
RUN apt-get -qq install cmake

RUN apt-get -qq install libboost-system1.67-dev libboost-filesystem1.67-dev libboost-coroutine1.67-dev \
		libboost-thread1.67-dev libboost-iostreams1.67-dev
RUN apt-get -qq install build-essential libtcmalloc-minimal4 && \
		ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so
