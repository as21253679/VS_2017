   M S B A M L   `   `   `  ���� U  QLiveCharts.Wpf, Version=0.9.7.0, Culture=neutral, PublicKeyToken=0bc1f845d1ebb8dfG4clr-namespace:LiveCharts.Wpf;assembly=LiveCharts.WpfLiveCharts.Wpf   	Wpf_chart   Wpf_chart.MainWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     @d2http://schemas.microsoft.com/expression/blend/2008     Dlvc4clr-namespace:LiveCharts.Wpf;assembly=LiveCharts.Wpf     -   .��� $��0,0,-0.4,19q�  � RowDefinitions  �� $
��Auto ��� $��* �.+�#   LiveCharts.Wpf.CartesianChart  -   $��Chart��&    LiveCharts.Wpf.Charts.Base.Chart   LegendLocation$ Right=�$��1��   Zoom$ Xy=�   DisableAnimations .    Series �� *SeriesCollection+   AxisY    LiveCharts.Wpf.Axis     Title$ UV��   MinValue$ 0Q�   MaxValue$	 255Q�	   LabelFormatter	 �� *
YFormatter+
   AxisX
   $
 TIME��   Labels �� *Labels+�� -    ��Name$ b2��$��顯示圖表��$
��Left=�$	��Top=�$��75���� -   $ b1��$��選擇檔案��$
��Left=�$��75,0,0,0q�$	��Top=�$��75���� -    ��Name$ label1��$��檔案路徑��$
��Left=�$��
150,-2,0,0q�$��2��$	��Top=��� -    ��Name$ 
scrollbar1��$
��Left=�$��0��$��0,0,0,0q�$��Bottom=�$��16��$��1�� J� RenderTransformOrigin$	 0,0&� � Maximum$	 100Q� � SmallChange$ 1Q� � LargeChange$	 100Q�z�V� .~��� �� ��  �� Angle$	 -90Q�T� 