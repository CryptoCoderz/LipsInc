LipsInc [LIPS] 2020 integration/staging tree
===============================================

https://lipsinc.xyz/

What is the LipsInc [LIPS] Blockchain?
------------------------------------
*TODO: Update documentation regarding implemented tech as this section is out of date and much progress and upgrades have been made to mentioned sections...*

### Overview
LipsInc is a blockchain project with the goal of offering secured messaging, websites on the chain and an overall pleasing experience to the user.

### Blockchain Technology
Blockchain technology has the capabilities to change a variety of things in the world and can also be the backbone of a new internet. One place that blockchain technology has not had an impact on yet is website on the blockchain. However, LipsInc is trying to change that and is well on their way to doing so.

### Custom Difficulty Retarget Algorithm “VRX”
VRX is designed from the ground up to integrate properly with the Velocity parameter enforcement system to ensure users no longer receive orphan blocks.

### Velocity Block Constraint System
Ensuring LipsInc stays as secure and robust as possible the CryptoCoderz team have implemented what's known as the Velocity block constraint system. This system acts as third and final check for both mined and peer-accepted blocks ensuring that all parameters are strictly enforced.

### HMQ1725 Algorithm
We use an custom internal algorithm known as HMQ1725 to sign blocks and conduct other functions, it takes its name from how it was designed: Highly-Modified-Quark 17-Algorithms 25-Scientific-Rounds

Specifications and General info
------------------
LipsInc uses:

		Boost1.72,
		OR Boost1.58,
		OpenSSL1.02u,
		OR OpenSSL1.1x,
		Berkeley DB 6.2.32,
		Qt5.14 to compile

General Info:


		Block Spacing: 5 Minutes
		Stake Minimum Age: 90 Confirmations (PoS-v3) | 2 Hours (PoS-v2)
		Port: 22448
		RPC Port: 22442

Compiling LipsInc daemon on Ubunutu 18.04 LTS Bionic
---------------------------
### Note: guide should be compatible with other Ubuntu versions from 14.04+

### Become poweruser
```
sudo -i
```

### Dependencies install
```
cd ~; sudo apt-get install ntp git build-essential libssl-dev libdb-dev libdb++-dev libboost-all-dev libqrencode-dev libcurl4-openssl-dev curl libzip-dev; apt-get update; apt-get upgrade; apt-get install git make automake build-essential libboost-all-dev; apt-get install yasm binutils libcurl4-openssl-dev openssl libssl-dev; sudo apt-get install libgmp-dev; cd ~;
```

### Dependencies build and link
```
cd ~; wget http://download.oracle.com/berkeley-db/db-6.2.32.NC.tar.gz; tar zxf db-6.2.32.NC.tar.gz; cd db-6.2.32.NC/build_unix; ../dist/configure --enable-cxx; make; sudo make install; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb-6.2.so /usr/lib/libdb-6.2.so; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb_cxx-6.2.so /usr/lib/libdb_cxx-6.2.so; export BDB_INCLUDE_PATH="/usr/local/BerkeleyDB.6.2/include"; export BDB_LIB_PATH="/usr/local/BerkeleyDB.6.2/lib"; cd ~;
```

### Personal upload EXAMPLE
```
cd ~; sudo cp -r /home/ftpuser/ftp/files/LIPS-clean/. ~/LipsInc
```

### GitHub pull RECOMMENDED
```
cd ~; git clone https://github.com/CryptoCoderz/LipsInc
```

### Build LipsInc daemon
```
cd ~; cd ~/LipsInc/src; chmod a+x obj; chmod a+x leveldb/build_detect_platform; chmod a+x leveldb; chmod a+x ~/LipsInc/src; chmod a+x ~/LipsInc; make -f ~/LipsInc/src/makefile/makefile.unix USE_UPNP=-; cd ~; cp ~/LipsInc/src/LipsIncd /usr/local/bin;
```

### Create config file for daemon
```
cd ~; sudo ufw allow 22448/tcp; sudo ufw allow 22442/tcp; sudo mkdir ~/.LIPS; cat << "CONFIG" >> ~/.LIPS/LipsInc.conf
listen=1
server=1
daemon=1
testnet=0
rpcuser=lipsincuser
rpcpassword=SomeCrazyVeryVerySecurePasswordHere
rpcport=22442
port=22448
rpcconnect=127.0.0.1
rpcallowip=127.0.0.1
addnode=198.50.180.207
addnode=85.255.7.52
addnode=195.181.211.221
addnode=176.31.205.41
addnode=116.14.167.86
addnode=167.99.171.227
addnode=174.107.102.219
addnode=176.9.156.236
addnode=198.50.180.193
addnode=94.130.64.143
addnode=145.239.65.6
addnode=108.61.175.156
addnode=46.4.27.201
addnode=149.56.154.75
addnode=50.46.99.238
addnode=159.89.114.40

CONFIG
chmod 700 ~/.LIPS/LipsInc.conf; chmod 700 ~/.LIPS; ls -la ~/.LIPS
```

### Run LipsInc daemon
```
cd ~; LipsIncd; LipsIncd getinfo
```

### Troubleshooting
### for basic troubleshooting run the following commands when compiling:
### this is for minupnpc errors compiling
```
make clean -f makefile.unix USE_UPNP=-
make -f makefile.unix USE_UPNP=-
```

License
-------

LipsInc [LIPS] is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/CryptoCoderz/LipsInc/tags) are created
regularly to indicate new official, stable release versions of LipsInc [LIPS].

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/bitcoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer Discord can be found at https://discord.gg/cn3AfPS .

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
