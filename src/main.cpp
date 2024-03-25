/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/modify/CCLabelBMFont.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <cctype>
#include <regex>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
        return false;
        
        auto gdlogo = CCSprite::create("GJ_LaunchSheet-uhd.png"_spr);

        auto gdtitle = static_cast<CCSprite*>(this->getChildByID("main-title"));
        
        gdtitle->setTexture(gdlogo->getTexture());

        return true;
    }
};

class $modify(CCLabelBMFont) {
    static CCLabelBMFont* create(char const* str, char const* fntFile) {
        std::string noxStr(str);

        //some weird code here, don't blame me, that's my first mod!
        std::vector<std::pair<std::regex, std::string>> noxMap = {
            {std::regex("A"), "D"},
            {std::regex("B"), "R"},
            {std::regex("C"), "J"},
            {std::regex("D"), "B"},
            {std::regex("E"), "F"},
            {std::regex("F"), "Z"},
            {std::regex("G"), "N"},
            {std::regex("H"), "L"},
            {std::regex("I"), "U"},
            {std::regex("J"), "X"},
            {std::regex("K"), "C"},
            {std::regex("L"), "V"},
            {std::regex("M"), "Q"},
            {std::regex("N"), "W"},
            {std::regex("O"), "E"},
            {std::regex("P"), "M"},
            {std::regex("Q"), "T"},
            {std::regex("R"), "Y"},
            {std::regex("S"), "U"},
            {std::regex("T"), "O"},
            {std::regex("U"), "P"},
            {std::regex("V"), "A"},
            {std::regex("W"), "S"},
            {std::regex("X"), "H"},
            {std::regex("Y"), "K"},
            {std::regex("Z"), "J"},
            {std::regex("a"), "d"},
            {std::regex("b"), "r"},
            {std::regex("c"), "j"},
            {std::regex("d"), "b"},
            {std::regex("e"), "f"},
            {std::regex("f"), "z"},
            {std::regex("g"), "n"},
            {std::regex("h"), "l"},
            {std::regex("i"), "u"},
            {std::regex("j"), "x"},
            {std::regex("k"), "c"},
            {std::regex("l"), "v"},
            {std::regex("m"), "q"},
            {std::regex("n"), "w"},
            {std::regex("o"), "e"},
            {std::regex("p"), "m"},
            {std::regex("q"), "t"},
            {std::regex("r"), "y"},
            {std::regex("s"), "u"},
            {std::regex("t"), "o"},
            {std::regex("u"), "p"},
            {std::regex("v"), "a"},
            {std::regex("w"), "s"},
            {std::regex("x"), "h"},
            {std::regex("y"), "k"},
            {std::regex("z"), "j"},
            {std::regex("0"), "9"},
            {std::regex("1"), "6"},
            {std::regex("2"), "4"},
            {std::regex("3"), "2"},
            {std::regex("4"), "7"},
            {std::regex("5"), "8"},
            {std::regex("6"), "1"},
            {std::regex("7"), "2"},
            {std::regex("8"), "3"},
            {std::regex("9"), "5"}
        };

        for (auto& rule : noxMap) {
            noxStr = std::regex_replace(noxStr, rule.first, rule.second);
        }


        bool noxConfig = Mod::get()->getSettingValue<bool>("noxx");
        if (noxConfig)  return CCLabelBMFont::create((noxStr + " nox").c_str(), fntFile);

        return CCLabelBMFont::create(noxStr.c_str(), fntFile);
    }
};