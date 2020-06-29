.$PSScriptRoot\GlobalConstants.ps1

if (Test-Path -Path $BuildTestDir -PathType Container) {
    Remove-Item -Recurse -Force $BuildTestDir
}
