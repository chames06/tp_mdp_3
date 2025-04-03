#include <iostream>
#include <string>
#include <random>

using namespace std;

class c_generateur_mdp {
public:
    // Constructeur : initialise l'alphabet et les bornes (nombre minimum et maximum de caractères)
    c_generateur_mdp(const string &alpha, unsigned short nbmin, unsigned short nbmax)
        : m_alphabet(alpha), m_nbMin(nbmin), m_nbMax(nbmax) {}

    // Vérifie que l'alphabet est valide (non vide)
    bool verifierAlphabet() {
        return !m_alphabet.empty();
    }

    // Génère et retourne un mot de passe aléatoire selon l'alphabet et la longueur souhaitée
    string genererMDP() {
        // Vérifie que l'alphabet est valide et que les bornes sont correctes
        if (!verifierAlphabet() || !verifierNbLettres())
            return "";

        // Création d'un générateur aléatoire
        std::random_device rd;
        std::mt19937 gen(rd());

        // Distribution pour déterminer la longueur du mot de passe entre m_nbMin et m_nbMax (inclus)
        std::uniform_int_distribution<> lenDist(m_nbMin, m_nbMax);
        int length = lenDist(gen);

        m_mdp.clear();
        // Distribution pour sélectionner un index dans l'alphabet
        std::uniform_int_distribution<> charDist(0, m_alphabet.size() - 1);

        for (int i = 0; i < length; i++) {
            m_mdp.push_back(m_alphabet[charDist(gen)]);
        }

        return m_mdp;
    }

    // Vérifie que le nombre maximum de lettres est strictement supérieur au nombre minimum
    bool verifierNbLettres() {
        return (m_nbMax > m_nbMin);
    }

private:
    string m_alphabet;          // Alphabet utilisé pour générer le mot de passe
    unsigned short m_nbMin;     // Nombre minimum de caractères du mot de passe
    unsigned short m_nbMax;     // Nombre maximum de caractères du mot de passe
    string m_mdp;               // Stocke le mot de passe généré
};

int main() {
    // Définition d'un alphabet comprenant lettres minuscules, majuscules, chiffres et symboles.
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    unsigned short minLettres = 8;
    unsigned short maxLettres = 15;

    // Création de l'objet générateur de mot de passe
    c_generateur_mdp generateur(alphabet, minLettres, maxLettres);

    // Vérification de la validité de l'alphabet
    if (!generateur.verifierAlphabet()) {
        cout << "Alphabet invalide." << endl;
        return 1;
    }

    // Vérification que le nombre maximum de lettres est bien supérieur au nombre minimum
    if (!generateur.verifierNbLettres()) {
        cout << "Les bornes du mot de passe ne sont pas correctes (max doit être supérieur au min)." << endl;
        return 1;
    }

    // Génération et affichage du mot de passe
    string mdp = generateur.genererMDP();
    cout << "Mot de passe généré : " << mdp << endl;

    return 0;
}
