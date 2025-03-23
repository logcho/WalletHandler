#ifndef WALLETHANDLER_H
#define WALLETHANDLER_H

#include <unordered_map>
#include <string>
#include "uint256_t/uint256_t.h"


class WalletHandler {
    private:
        std::string tokenAddress;
        std::unordered_map<std::string, uint256_t> wallet;

        // Helper function for token address validation
        bool isValidToken(const std::string& token) const {
            return token == tokenAddress;
        }

    public:
        WalletHandler(const std::string& tokenAddress){
            WalletHandler::tokenAddress = tokenAddress;
        }

        void depositToken(const std::string& tokenAddress, const std::string& address, uint256_t amount){
            if(isValidToken(tokenAddress)){
                wallet[address] += amount; // Add amount to the existing balance
            }
        }

        void depositToken(const std::string& tokenAddress, const std::string& address, std::string hexAmount){
            uint256_t amount(hexAmount);
            if(isValidToken(tokenAddress)){
                wallet[address] += amount; // Add amount to the existing balance
            }
        }

        void withdrawToken(const std::string& address, uint256_t amount){
            if(isValidToken(tokenAddress)){
                wallet[address] -= amount; // Deduct amount from balance
            }
        }

        void withdrawToken(const std::string& address, uint256_t hexAmount){
            uint256_t amount(hexAmount);
            if(isValidToken(tokenAddress)){
                wallet[address] -= amount; // Deduct amount from balance
            }
        }

        void transferToken(const std::string& tokenAddress, const std::string& from, const std::string& to, uint256_t amount) {
            if (isValidToken(tokenAddress) && wallet[from] >= amount) {
                wallet[from] -= amount;
                wallet[to] += amount;
            }
        }
        
        void transferERC20(const std::string& tokenAddress, const std::string& from, const std::string& to, const std::string& hexAmount) {
            uint256_t amount(hexAmount);
            if (isValidToken(tokenAddress) && wallet[from] >= amount) {
                wallet[from] -= amount;
                wallet[to] += amount;
            }
        }

        uint256_t getTokenBalance(const std::string& address){
            auto it = wallet.find(address);
            return (it != wallet.end()) ? it->second : uint256_t(0); // Return balance or 0 if not found 
        }
};

#endif // WALLETHANDLER_H