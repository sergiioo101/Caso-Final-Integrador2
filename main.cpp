#include <vector>
#include <string>
#include <map>

enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

struct Entorno;

class Variant {
public:
    typedef Variant (*proc_type)(const std::vector<Variant>&);
    typedef std::vector<Variant>::const_iterator iter;
    typedef std::map<std::string, Variant> map;

    variant_type type;
    std::string val;
    std::vector<Variant> list;
    proc_type proc;
    Entorno* env;

    Variant(variant_type type = Symbol) : type(type), env(0), proc(0) {}
    Variant(variant_type type, const std::string& val) : type(type), val(val), env(0), proc(0) {}
    Variant(proc_type proc) : type(Proc), proc(proc), env(0) {}

    std::string to_string();
    std::string to_json_string();
    static Variant from_json_string(std::string json);
};

std::string Variant::to_string() {
    // Tu implementación aquí
    return "";  // Asegúrate de agregar una implementación adecuada
}

std::string Variant::to_json_string() {
    // Tu implementación aquí
    return "";  // Asegúrate de agregar una implementación adecuada
}

Variant Variant::from_json_string(std::string sjson) {
    // Tu implementación aquí
    return Variant();  // Asegúrate de agregar una implementación adecuada
}

#include <iostream>

int main() {
    // Crear instancias de Variant
    Variant symbolVariant(Symbol);
    Variant numberVariant(Number, "42");
    Variant listVariant(List);
    Variant procVariant([](const std::vector<Variant>& args) { return Variant(); });

    // Mostrar información sobre las instancias
    std::cout << "Symbol Variant Type: " << symbolVariant.type << std::endl;
    std::cout << "Number Variant Type: " << numberVariant.type << ", Value: " << numberVariant.val << std::endl;
    std::cout << "List Variant Type: " << listVariant.type << std::endl;
    std::cout << "Proc Variant Type: " << procVariant.type << std::endl;

    // Convertir a cadena y mostrar
    std::cout << "Number Variant to String: " << numberVariant.to_string() << std::endl;

    // Crear un mapa de Variant
    Variant::map variantMap;
    variantMap["key1"] = Variant(Symbol);
    variantMap["key2"] = Variant(Number, "123");

    // Mostrar información del mapa
    std::cout << "Variant Map Size: " << variantMap.size() << std::endl;
    std::cout << "Value for key1: " << variantMap["key1"].to_string() << std::endl;

    // Convertir a cadena JSON y mostrar
    std::string jsonStr = numberVariant.to_json_string();
    std::cout << "Number Variant as JSON: " << jsonStr << std::endl;

    // Crear una instancia de Variant a partir de una cadena JSON
    Variant jsonVariant = Variant::from_json_string(jsonStr);
    std::cout << "Variant from JSON: " << jsonVariant.to_string() << std::endl;

    return 0;
}


