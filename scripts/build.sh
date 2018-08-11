#/usr/bin/env bash

set -xeu
set -o pipefail

script_dir=$(cd $(dirname $0) || exit 1; pwd)
pushd $script_dir/../../

sudo apt-get update
sudo apt-get install -y glib-2.0 gtk+-3.0

# Documentation
# sudo apt-get install -y markdown tardy texlive hevea
# texlive-full: 1GB ?

# Compiler
# sudo apt-get install -y gcc-8 g++-8 gcc-8-plugin-dev libgccjit-8-dev

#
# Libonion
#
if [[ ! -d libonion ]]; then
  git clone https://github.com/davidmoreno/onion libonion
fi

mkdir -p libonion-build
mkdir -p libonion-install

Libonion_ROOT=$(pwd)/libonion-install
cmake -Hlibonion -Blibonion-build -G Ninja \
  -DCMAKE_INSTALL_PREFIX:PATH=${Libonion_ROOT} \
  -DONION_EXAMPLES:BOOL=OFF
cmake --build libonion-build --target install

#
# libbacktrace
#
if [[ ! -d libbacktrace ]]; then
  git clone https://github.com/ianlancetaylor/libbacktrace.git
fi
pushd libbacktrace
libbacktrace_ROOT=$(pwd)/../libbacktrace-install
./configure --prefix=${libbacktrace_ROOT}
make -j4
make install
popd

#
# bismon
#
cmake -G Ninja -Hbismon -Bbismon-build \
  -DLibonion_ROOT:PATH=${Libonion_ROOT} \
  -Dlibbacktrace_ROOT:PATH=${libbacktrace_ROOT}
cmake --build bismon-build

