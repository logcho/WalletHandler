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

        void depositERC20(const std::string& address, uint256_t amount){
            erc20[address] += amount; // Add amount to the existing balance
        }
        void withdrawERC20(const std::string& address, uint256_t amount){
            erc20[address] -= amount; // Deduct amount from balance
        }
        uint256_t getERC20Balance(const std::string& address){
            auto it = erc20.find(address);
            return (it != erc20.end()) ? it->second : uint256_t(0); // Return balance or 0 if not found 
        }
};

#endif // WALLET_H