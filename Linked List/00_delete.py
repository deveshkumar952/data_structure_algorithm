import os

def delete_exe_file(folder_path):
    # List all files in the folder
    files = os.listdir(folder_path)
    
    # Iterate through the files
    for file in files:
        if file.endswith(".exe"):  # Check if file is an executable (.exe) file
            file_path = os.path.join(folder_path, file)
            # Attempt to delete the file
            try:
                os.remove(file_path)
                print(f"Deleted: {file}")
            except OSError as e:
                print(f"Error: {file} - {e.strerror}")

# Example usage:
folder_path = r"C:\Users\Deves\OneDrive\Desktop\DSA\code\Linked List"  # Specify the folder path
delete_exe_file(folder_path)
