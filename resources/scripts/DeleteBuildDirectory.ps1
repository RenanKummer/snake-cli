.$PSScriptRoot\GlobalConstants.ps1

if (Test-Path -Path $BuildDir -PathType Container) {
    Remove-Item -Recurse -Force $BuildDir
}
