# Comandos Básicos do Linux

Este documento apresenta alguns comandos básicos do Linux, suas funções e exemplos de uso.

## Comandos de Navegação e Manipulação de Diretórios

- `ls -l` → Lista os arquivos e diretórios no formato detalhado.
- `cd Doc` + `TAB` → Navega até o diretório `Doc` com a conclusão automática.
- `pwd` → Exibe o caminho completo do diretório atual.
- `mkdir aluno` → Cria um diretório chamado `aluno`.
- `cd aluno` → Entra no diretório `aluno`.
- `cd ..` → Retorna ao diretório anterior.
- `rmdir aluno` → Remove o diretório `aluno` (se estiver vazio).

## Comandos de Manipulação de Arquivos

- `man pwd` → Exibe o manual do comando `pwd`.
- `gedit novo.txt` → Abre ou cria o arquivo `novo.txt` no editor de texto `gedit`.
- `cp novo.txt copia.txt` → Copia `novo.txt` para `copia.txt`.
- `mv copia.txt texto.txt` → Renomeia `copia.txt` para `texto.txt`.
- `rm novo.txt` → Remove o arquivo `novo.txt`.
- `rm *.txt` → Remove todos os arquivos com extensão `.txt` no diretório atual.
- `rm *.*` → Remove todos os arquivos no diretório atual (use com cautela!).

## Comandos de Monitoramento e Sistema

- `strace pwd` → Mostra as chamadas de sistema feitas pelo comando `pwd`.
- `clear` → Limpa o terminal.
- `more <arquivo>` → Exibe o conteúdo de um arquivo paginadamente.
- `ps` → Lista os processos em execução do usuário atual.
- `ps aux` → Exibe todos os processos ativos no sistema.
- `top` → Mostra os processos em execução e o uso de recursos em tempo real.
- `pstree` → Exibe os processos em execução de forma hierárquica.

## Editores de Texto

- `gedit` → Editor gráfico simples para textos.
- `nano` → Editor de texto no terminal, fácil de usar.
- `vim` → Editor de texto avançado no terminal, requer comandos específicos.

---

### Observações:
- Para comandos que envolvem remoção de arquivos (`rm`), tenha cuidado, pois os arquivos deletados não vão para a lixeira.
- O comando `mv` pode ser usado tanto para mover quanto para renomear arquivos.
- `strace` pode não estar instalado por padrão; se necessário, instale com `sudo apt install strace` (Debian/Ubuntu).
- Para fechar o `top`, use `q`.
- Para sair do `vim`, use `:q!` (sem salvar) ou `:wq` (salvar e sair).

Esse documento serve como um guia básico para usuários iniciantes no Linux.

