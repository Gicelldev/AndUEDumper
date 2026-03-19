#pragma once

#include "../UEGameProfile.hpp"
using namespace UEMemory;

class PUBGProfile : public IGameProfile
{
public:
    PUBGProfile() = default;

    bool ArchSupprted() const override { return true; }
    std::string GetAppName() const override { return "PUBG"; }
    std::vector<std::string> GetAppIDs() const override {
        return { "com.tencent.ig", "com.rekoo.pubgm", "com.pubg.imobile", "com.pubg.krmobile", "com.vng.pubgmobile" };
    }
    bool isUsingCasePreservingName() const override { return false; }
    bool IsUsingFNamePool() const override { return true; } // Biasanya 64bit sudah FNamePool
    bool isUsingOutlineNumberName() const override { return false; }

    uintptr_t GetGUObjectArrayPtr() const override {
        // Menggunakan offset Ue4Pointer dari forum
        return GetUnrealELF().base() + 0xE0C36E0;
    }

    uintptr_t GetNamesPtr() const override {
        // Menggunakan offset Gname dari forum
        return GetUnrealELF().base() + 0xE498300;
    }

    UE_Offsets *GetOffsets() const override {
        // Asumsi UE 4.25+ untuk 64-bit modern (berbeda dengan 32-bit lama)
        static UE_Offsets offsets = UE_DefaultOffsets::UE4_25_27(isUsingCasePreservingName());
        return &offsets;
    }
};
