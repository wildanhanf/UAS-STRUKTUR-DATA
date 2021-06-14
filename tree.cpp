#include <iostream>

struct Node {
    std::string name;
    int limit;
    Node *left;
    Node *right;
};

Node* CreateNode(std::string name, int limit = 0)
{
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Error\n";
        return nullptr;
    }
    newNode->name = name;
    newNode->limit= limit;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

std::string decision(Node* temp, int beratBadan, int bentukBadan, int tinggiBadan) {
    if (temp->left == nullptr && temp->right == nullptr)
        return temp->name;

    if (temp->name == "Berat Badan"){
        if(beratBadan < temp->limit) return decision(temp->left, beratBadan, bentukBadan, tinggiBadan);  
        return decision(temp->right, beratBadan, bentukBadan, tinggiBadan);
    }
    
    if(temp->name == "Bentuk Badan"){
        if(bentukBadan == 0) return decision(temp->left, beratBadan, bentukBadan, tinggiBadan);
        return decision(temp->right, beratBadan, bentukBadan, tinggiBadan);
    }

    if(temp->name == "Tinggi Badan"){
        if(tinggiBadan < temp->limit) return decision(temp->left, beratBadan, bentukBadan, tinggiBadan);
        return decision(temp->right, beratBadan, bentukBadan, tinggiBadan); 
    }
    
    return "Salah";
}

void kelolaData(Node* root) {
    int beratBadan, bentukBadan, tinggiBadan;
    std::cout << "Berat badan (jika desimal bulatkan ke satuan terdekat dalam KG): ";
    std::cin >> beratBadan;
    std::cout << "Bentuk badan (0 = Kurus, 1 = Nornal): ";
    std::cin >> bentukBadan;
    std::cout << "Tinggi Badan (CM): ";
    std::cin >> tinggiBadan;
    if(beratBadan > 17) {
        std::cout << "\nBerat badan di atas rata-rata normal";
        exit(0);
    }
    if (bentukBadan < 0 || bentukBadan > 1){
        std::cout << "\nInput Salah ";
        exit(0);
    }
    if(tinggiBadan > 100){
        std::cout << "\nTinggi badan di atas rata-rata normal";
        exit(0);
    }

    std::cout << "\n" << decision(root, beratBadan, bentukBadan, tinggiBadan);
}

int main(){
    int umur, limit, beratBadan, bentukBadan, tinggiBadan;
    char jk; std::string name;

    std::cout << "===== KLASIFIKASI STATUS GIZI BALITA 1-5 TAHUN =====\n\n";
    
    std::cout << "Masukkan Jenis Kelamin (L/P): "; 
    std::cin >> jk;

    if(jk == 'L' || jk == 'l'){
    std::cout << "Masukkan Umur (1-5 tahun): ";
    std::cin >> umur;

    switch (umur)
    {
    case 1:
    {
        Node* root = CreateNode("Berat Badan", 8);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 72);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 72);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    case 2:
    {
        Node* root = CreateNode("Berat Badan", 10);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 82);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 82);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    case 3:
    {
        Node* root = CreateNode("Berat Badan", 12);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 88);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 88);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    case 4:
    {
        Node* root = CreateNode("Berat Badan", 13);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 95);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 95);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    case 5:
    {
        Node* root = CreateNode("Berat Badan", 15);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 100);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 100);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    default:
        std::cout << "\nINput Salah";
        break;
    }  
    } else if (jk == 'P' || jk == 'p'){
    std::cout << "Masukkan Umur (1-5): ";
    std::cin >> umur;
    switch (umur)
    {
    case 1:
    {
        Node* root = CreateNode("Berat Badan", 7);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 69);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 69);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    case 2:
    {
        Node* root = CreateNode("Berat Badan", 9);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 80);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 80);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    case 3:
    {
        Node* root = CreateNode("Berat Badan", 11);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 87);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 87);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    case 4:
    {
        Node* root = CreateNode("Berat Badan", 12);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 94);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 94);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    case 5:
    {
        Node* root = CreateNode("Berat Badan", 14);
        root->left = CreateNode("Bentuk Badan", 0);
        root->right = CreateNode("Bentuk Badan", 0);

        root->left->left = CreateNode("Gizi Kurang");
        root->left->right = CreateNode("Tinggi Badan", 99);
        root->left->right->left = CreateNode("Gizi Kurang");
        root->left->right->right = CreateNode("Gizi Cukup");

        root->right->left = CreateNode("Tinggi Badan", 99);
        root->right->right = CreateNode("Gizi Cukup");
        root->right->left->left = CreateNode("Gizi Kurang");
        root->right->left->right = CreateNode("Gizi CUkup");
        kelolaData(root);
        break;
    }
    default:
        std::cout << "\nInput Salah";
        break;
    }
    } else {
        std::cout << "\nInput salah";
        exit;
    }
}