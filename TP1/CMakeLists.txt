# Ceci est un commentaire.
# Retirez le # pour que l'instruction soit prise en compte.

# La commande ci-dessous permet de générer un exécutable à partir des fichiers spécifiés.
add_executable(
    hello-world
    helloworld.cpp)
target_compile_features(hello-world PRIVATE cxx_std_17)

target_compile_options(hello-world PRIVATE
-Wall
-Wextra
#-Werror
)