import os

# Novo include que será substituído
novo_include = '#include "../include/libft.h"'

# Caminho do diretório onde estão os arquivos .c
diretorio = "./"

# Percorre todos os arquivos no diretório e subdiretórios
for root, _, files in os.walk(diretorio):
    for file in files:
        if file.endswith(".c"):  # Apenas arquivos com extensão .c
            caminho_arquivo = os.path.join(root, file)

            # Lê o conteúdo do arquivo
            with open(caminho_arquivo, "r", encoding="utf-8") as f:
                conteudo = f.readlines()

            # Verifica e edita o #include existente
            alterado = False
            for i, linha in enumerate(conteudo):
                if linha.strip().startswith("#include"):  # Linha com #include
                    conteudo[i] = novo_include + "\n"  # Substitui pelo novo
                    alterado = True
                    break

            # Se algo foi alterado, escreve de volta no arquivo
            if alterado:
                with open(caminho_arquivo, "w", encoding="utf-8") as f:
                    f.writelines(conteudo)

                print(f"Include atualizado no arquivo: {caminho_arquivo}")

