/* Copyright 2021 Priscila Angel Rodrigues Silva */
// LINK DO REPOSITÓRIO: https://github.com/priscila-eng/TrabalhoMP
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romano.hpp"

TEST_CASE("Verifica se a string tem mais de 30 caracteres", "[romanToInt]") {
    REQUIRE(romanToInt("MMMCMXCIXMMMCMXCIXMMMCMXCIXMMMCMXCIX") == -1);
}
TEST_CASE("Verifica se o valor é maior que 3000", "[romanToInt]") {
    REQUIRE(romanToInt("MMM") == 3000);
    REQUIRE(romanToInt("MMMCMXCIX") == -1);
}

TEST_CASE("Verifica se são calculados", "[romanToInt]") {
    REQUIRE(romanToInt("III") == 3);
    REQUIRE(romanToInt("XX") == 20);
    REQUIRE(romanToInt("IVDCCC") == 794);
    REQUIRE(romanToInt("CM") == 900);
    REQUIRE(romanToInt("XXXIX") == 39);
}

TEST_CASE("Verifica se é um caracter inválido", "[romanToInt") {
    REQUIRE(romanToInt("x") == -1);
    REQUIRE(romanToInt("i") == -1);
    REQUIRE(romanToInt("O") == -1);
    REQUIRE(romanToInt("Xi") == -1);
}

TEST_CASE("Verifica se é um caracter válido", "[romanToInt") {
    REQUIRE(romanToInt("I") == 1);
    REQUIRE(romanToInt("V") == 5);
    REQUIRE(romanToInt("X") == 10);
    REQUIRE(romanToInt("L") == 50);
    REQUIRE(romanToInt("C") == 100);
    REQUIRE(romanToInt("D") == 500);
    REQUIRE(romanToInt("M") == 1000);
}

TEST_CASE("Verifica se tem mais de 3 repetições", "[romanToInt]") {
    REQUIRE(romanToInt("IIII") == -1);
    REQUIRE(romanToInt("XXXX") == -1);
    REQUIRE(romanToInt("CCCC") == -1);
    REQUIRE(romanToInt("MMMMMMMM") == -1);
}

TEST_CASE("Verifica se tem repetições", "[romanToInt]") {
    REQUIRE(romanToInt("VV") == -1);
    REQUIRE(romanToInt("LL") == -1);
    REQUIRE(romanToInt("DD") == -1);
}

TEST_CASE("O I tem que vir antes do V e do X", "[romanToInt]") {
    REQUIRE(romanToInt("IV") == 4);
    REQUIRE(romanToInt("IX") == 9);
    REQUIRE(romanToInt("IL") == -1);
    REQUIRE(romanToInt("IC") == -1);
    REQUIRE(romanToInt("ID") == -1);
    REQUIRE(romanToInt("IM") == -1);
}

TEST_CASE("O X so pode vir antes do I, V, X, L e do C", "[romanToInt]") {
    REQUIRE(romanToInt("XI") == 11);
    REQUIRE(romanToInt("XV") == 15);
    REQUIRE(romanToInt("XL") == 40);
    REQUIRE(romanToInt("XC") == 90);
    REQUIRE(romanToInt("XD") == -1);
    REQUIRE(romanToInt("XM") == -1);
}
