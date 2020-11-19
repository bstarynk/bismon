#    BISMON 
#    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.


FROM ubuntu:18.04
MAINTAINER Niklas Rosencrantz (niklasro@gmail.com)
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update
RUN apt-get install --yes software-properties-common
RUN apt-add-repository --yes --update ppa:ubuntu-toolchain-r/test
RUN apt-get update
RUN apt-get update && apt-get install --yes git gcc-snapshot && apt-get autoremove && apt-get autoclean
RUN apt-get install --yes build-essential make gcc-8 cmake ninja-build g++-8 gcc-8-plugin-dev libgccjit-8-dev libgtk-3-dev markdown indent astyle tardy texlive texlive-full hevea
RUN adduser --disabled-password --gecos '' newuser
USER newuser
WORKDIR /home/newuser
RUN git clone https://github.com/ianlancetaylor/libbacktrace.git
RUN cd libbacktrace; ./configure ; make
USER root
WORKDIR /home/newuser/libbacktrace
RUN make install
USER newuser
RUN cd; git clone https://github.com/davidmoreno/onion.git; cd onion; mkdir build; cd build; cmake ..; make
USER root
WORKDIR /home/newuser/onion/build
RUN make install; cp /usr/local/lib/libonion* /usr/lib; cp /usr/local/lib/libbacktrace* /usr/lib
USER newuser
RUN cd; git clone https://github.com/bstarynk/bismon.git; cd bismon; make; touch ~/passwords_BM; chmod u+rw,go-rwx ~/passwords_BM
WORKDIR /home/newuser/bismon
