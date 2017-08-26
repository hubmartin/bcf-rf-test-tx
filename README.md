<<<<<<< HEAD
<a href="https://www.bigclown.com"><img src="https://s3.eu-central-1.amazonaws.com/bigclown/gh-readme-logo.png" alt="BigClown Logo" align="right"></a>

# Firmware for BigClown Generic Node

[![Travis](https://img.shields.io/travis/bigclownlabs/bcf-generic-node/master.svg)](https://travis-ci.org/bigclownlabs/bcf-generic-node)
[![Release](https://img.shields.io/github/release/bigclownlabs/bcf-generic-node.svg)](https://github.com/bigclownlabs/bcf-generic-node/releases)
[![License](https://img.shields.io/github/license/bigclownlabs/bcf-generic-node.svg)](https://github.com/bigclownlabs/bcf-generic-node/blob/master/LICENSE)
[![Twitter](https://img.shields.io/twitter/follow/BigClownLabs.svg?style=social&label=Follow)](https://twitter.com/BigClownLabs)

This repository contains firmware for BigClown Generic Node.

## Firmware Programming
```
dfu-util -s 0x08000000:leave -d 0483:df11 -a 0 -D firmware.bin
```
More information about dfu [here](https://doc.bigclown.com/core-module-flashing.html)

Firmware for gateway is here [https://github.com/bigclownlabs/bcf-usb-gateway](https://github.com/bigclownlabs/bcf-usb-gateway)

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT/) - see the [LICENSE](LICENSE) file for details.

---

Made with &#x2764;&nbsp; by [BigClown Labs s.r.o.](https://www.bigclown.com) in Czech Republic.
=======
# bcf-rf-test-tx
RF range test firmware, this TX side needs just Core Module
>>>>>>> 8f293c5c635d947b4aaff1f00fb803cbf03940f2
