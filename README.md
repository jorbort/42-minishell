## Descripción

**Minishell** es un shell interactivo que permite ejecutar comandos similares a los de `bash`.

## Instalación

1. Clona este repositorio:
   ```bash
   git clone https://github.com/jorbort/42-minishell
   cd minishell
   ```
2. Compila el proyecto ejecutando el siguiente comando:
   ```bash
   make
   ```

Esto generará el ejecutable `minishell`.

## Ejecución

Ejecuta el shell utilizando el comando:
```bash
./minishell
```

## Características Principales

- **Historial de Comandos**: Usa las flechas del teclado para navegar por los comandos previamente ejecutados.
- **Soporte para Redirecciones**:
  - Entrada: `< archivo`
  - Salida: `> archivo`
  - Heredoc: `<< delimitador`
  - Salida en modo append: `>> archivo`
- **Pipes**: Encadena comandos con `|`, por ejemplo:
  ```bash
  ls | grep minishell
  ```
- **Variables de Entorno**: Usa `$NOMBRE_VARIABLE` para acceder al valor de una variable de entorno.
- **Señales**:
  - `Ctrl+C`: Muestra un nuevo prompt.
  - `Ctrl+D`: Cierra el shell.
  - `Ctrl+\`: No realiza ninguna acción.

## Builtins

El shell incluye los siguientes comandos internos:

1. **echo**:
   ```bash
   echo [-n] "texto"
   ```
   Usa la opción `-n` para evitar un salto de línea.

2. **cd**:
   ```bash
   cd [ruta]
   ```
   Cambia el directorio actual.

3. **pwd**:
   ```bash
   pwd
   ```
   Muestra el directorio actual.

4. **export**:
   ```bash
   export NOMBRE=valor
   ```
   Define o modifica una variable de entorno.

5. **unset**:
   ```bash
   unset NOMBRE
   ```
   Elimina una variable de entorno.

6. **env**:
   ```bash
   env
   ```
   Muestra las variables de entorno actuales.

7. **exit**:
   ```bash
   exit [código]
   ```
   Sale del shell con un código de estado opcional.

## Ejemplos de Uso

- Redirecciones:
  ```bash
  cat < archivo.txt
  ls > salida.txt
  grep "minishell" >> salida.txt
  ```

- Pipes:
  ```bash
  ls | grep minishell | wc -l
  ```

- Variables de entorno:
  ```bash
  export PATH=/mi/nuevo/path
  echo $PATH
  ```
