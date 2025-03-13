import subprocess
import sys
import os

def extract_file(file_path, dest_path='.'):
    if not os.path.exists(file_path):
        print(f"File {file_path} does not exist.")
        return

    if not os.path.exists(dest_path):
        os.makedirs(dest_path)

    if file_path.endswith('.tar'):
        command = ['tar', '-xvf', file_path, '-C', dest_path]
    elif file_path.endswith('.tar.gz') or file_path.endswith('.tgz'):
        command = ['tar', '-xzvf', file_path, '-C', dest_path]
    elif file_path.endswith('.gz'):
        command = ['gunzip', '-c', file_path, '>', os.path.join(dest_path, os.path.basename(file_path).replace('.gz', ''))]
    elif file_path.endswith('.tar.bz2'):
        command = ['tar', '-xjvf', file_path, '-C', dest_path]
    elif file_path.endswith('.tar.Z'):
        command = ['tar', '-xZvf', file_path, '-C', dest_path]
    elif file_path.endswith('.rar'):
        command = ['unrar', 'e', file_path, dest_path]
    elif file_path.endswith('.zip'):
        command = ['unzip', file_path, '-d', dest_path]
    elif file_path.endswith('.tar.xz'):
        command = ['tar', '-xvf', file_path, '-C', dest_path]
    else:
        print(f"Unsupported file type: {file_path}")
        return

    try:
        subprocess.run(command, check=True)
        print(f"Extracted {file_path} to {dest_path}")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while extracting {file_path}: {e}")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: te <file> [dest_path]")
    elif len(sys.argv) == 2:
        extract_file(sys.argv[1])
    else:
        extract_file(sys.argv[1], sys.argv[2])