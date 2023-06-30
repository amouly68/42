# -*- coding: utf-8 -*-

import os

def create_cpp_files():
    # Demander le nom de la classe à créer
    class_name = input("Entrez le nom de la classe à créer : ")

    # Vérifier si le dossier "include" existe, sinon le créer
    include_dir = "include"
    if not os.path.exists(include_dir):
        os.makedirs(include_dir)
    
    # Vérifier si le dossier "src" existe, sinon le créer
    src_dir = "src"
    if not os.path.exists(src_dir):
        os.makedirs(src_dir)
    
    # Vérifier si le fichier .hpp existe déjà
    hpp_file_path = os.path.join(include_dir, class_name + ".hpp")
    if os.path.exists(hpp_file_path):
        print("Le fichier {}.hpp existe déjà.".format(class_name))
        return
    
    # Créer le fichier .hpp dans le dossier "include"
    hpp_content = """#ifndef {}_HPP
#define {}_HPP

class {} {{
public:
    // Descripteur
    {}();

private:
    // TODO: Définir les membres de données

}};

#endif // {}_HPP
""".format(class_name.upper(), class_name.upper(), class_name, class_name, class_name.upper())
    
    with open(hpp_file_path, "w") as hpp_file:
        hpp_file.write(hpp_content)
    
    print("Fichier {}.hpp créé dans le dossier {}.".format(class_name, include_dir))
    
    # Vérifier si le fichier .cpp existe déjà
    cpp_file_path = os.path.join(src_dir, class_name + ".cpp")
    if os.path.exists(cpp_file_path):
        print("Le fichier {}.cpp existe déjà.".format(class_name))
        return
    
    # Créer le fichier .cpp dans le dossier "src"
    cpp_content = """#include "../{}/{}.hpp"

{}::{}() {{
    // TODO: Implémenter le constructeur
}}

// TODO: Implémenter les autres fonctions de la classe {}

""".format(include_dir, class_name, class_name, class_name)
    
    with open(cpp_file_path, "w") as cpp_file:
        cpp_file.write(cpp_content)
    
    print("Fichier {}.cpp créé dans le dossier {}.".format(class_name, src_dir))


# Exemple d'utilisation
create_cpp_files()
