.$PSScriptRoot\GlobalConstants.ps1

Set-Variable -Name ExitCode -Value 0
Write-Output ""
Get-ChildItem -Path $BuildTestBinDir -Filter *.exe | ForEach-Object {
    &$_.FullName /s
    
    if (!$?) {
        Set-Variable -Name ExitCode -Value 1
    }
}
exit $ExitCode
