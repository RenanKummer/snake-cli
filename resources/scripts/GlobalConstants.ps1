Set-Variable -Name WorkingPath -Value $PSScriptRoot.Remove($PSScriptRoot.LastIndexOf('\'))
Set-Variable -Name WorkingPath -Value $WorkingPath.Remove($WorkingPath.LastIndexOf('\'))

Set-Variable -Name RootDir -Value $WorkingPath -Option Constant
Set-Variable -Name BuildDir -Value  "$RootDir\build" -Option Constant
Set-Variable -Name BuildTestDir -Value "$BuildDir\test" -Option Constant
Set-Variable -Name BuildMainBinDir -Value "$BuildDir\main\bin" -Option Constant
Set-Variable -Name BuildMainObjDir -Value "$BuildDir\main\obj" -Option Constant
Set-Variable -Name BuildTestBinDir -Value "$BuildTestDir\bin" -Option Constant
Set-Variable -Name BuildTestObjDir -Value "$BuildTestDir\obj" -Option Constant
