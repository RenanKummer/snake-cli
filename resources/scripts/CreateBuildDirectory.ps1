.$PSScriptRoot\GlobalConstants.ps1

if (-not (Test-Path -Path $BuildMainBinDir -PathType Container)) {
    New-Item -Path $BuildMainBinDir -ItemType Directory | Out-Null
}

if (-not (Test-Path -Path $BuildMainObjDir -PathType Container)) {
    New-Item -Path $BuildMainObjDir -ItemType Directory | Out-Null
}

if (-not (Test-Path -Path $BuildTestBinDir -PathType Container)) {
    New-Item -Path $BuildTestBinDir -ItemType Directory | Out-Null
}

if (-not (Test-Path -Path $BuildTestObjDir -PathType Container)) {
    New-Item -Path $BuildTestObjDir -ItemType Directory | Out-Null
}
