#ifndef WALLET_H
#define WALLET_H

#include <unordered_map>
#include <string>
#include "uint256_t/uint256_t.h"


class Wallet {
    private:
        std::unordered_map<std::string, uint256_t> erc20;
    public:
        Wallet();

        void depositERC20(const std::string& address, uint256_t amount);
        void withdrawERC20(const std::string& address, uint256_t amount);
        uint256_t getERC20Balance(const std::string& address);
};

#endif // WALLET_H