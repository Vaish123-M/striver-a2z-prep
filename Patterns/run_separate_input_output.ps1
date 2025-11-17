<#
Helper: run program in one terminal and send input from another.
Usage (in VS Code integrated terminal):

1) Open TWO terminals side-by-side in VS Code (Terminal → New Terminal twice).

2) In the left (OUTPUT) terminal run the program and read stdin from a file stream:
   cd "${PWD}"
   Get-Content .\input.txt -Wait | .\Pattern6.exe

   - `Get-Content -Wait` streams appended lines from `input.txt` into the program's stdin.
   - This terminal will show the program's output.

3) In the right (INPUT) terminal edit or append lines to `input.txt` to send input to the program:
   # Replace the file contents (overwrite):
   Set-Content .\input.txt -Value "1`n5`n"

   # Append a new line (send additional input):
   Add-Content .\input.txt -Value "2"

   # Or open the file in the editor and save — the left terminal will pick up appended lines.

Notes / tips:
- Make sure `input.txt` exists before you start the output terminal.
- When the program exits, `Get-Content -Wait` will continue waiting for more input until you stop it (Ctrl+C).
- This technique works well for simple interactive-like flows where the program reads from stdin and you want to prepare input from a different terminal.
- For one-shot runs, you can still use redirection: .\Pattern6.exe < .\input.txt
#>

Write-Host "Run this script for usage instructions. To actually run, follow the instructions inside the file." -ForegroundColor Cyan
