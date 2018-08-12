#/usr/bin/env bash

set -xeu
set -o pipefail

script_dir=$(cd $(dirname $0) || exit 1; pwd)
pushd $script_dir/../../bismon-build

password_BM=$(pwd)/passwords_BM
touch ${password_BM}
chmod u+rw,go-rwx ${password_BM}

contributors_BM=$(pwd)/contributors_BM
touch $contributors_BM

./bismonion --contributor="Alan Turing;alan@fake.email;turing@localhost" --batch --dump-after-load=.

echo "Alan Turing:mypass!123456" > /tmp/addpassbismon
./bismonion--add-passwords=/tmp/addpassbismon --batch --dump-after-load=.
