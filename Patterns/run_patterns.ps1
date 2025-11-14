# Compile and run pattern examples with sample input.
# Usage: Right-click and 'Run PowerShell' or run in integrated terminal.

$patterns = @("Pattern5.cpp","Pattern6.cpp")

foreach ($src in $patterns) {
    $exe = [System.IO.Path]::ChangeExtension($src, ".exe")
    Write-Host "Compiling $src -> $exe"
    g++ $src -o $exe
    if ($LASTEXITCODE -ne 0) {
        Write-Error "Compilation failed for $src"
        continue
    }

    Write-Host "Running $exe with sample input (t=1, n=5):`n"
    @"
1
5
"@ | .\$exe
    Write-Host "`n---`n"
}

Write-Host "Done."
