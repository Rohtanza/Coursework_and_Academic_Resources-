using Gtk;
using System;

namespace CalculatorApp
{
    partial class Program
    {
        static string operator1;
        static Entry entry;
        static double[] operands;
        static Operation lastOperation = Operation.None;
        static bool resultShown = false; 
        private static Window window = null;
        private static Grid grid = null;
        private static Button[,] buttons = new Button[5, 5];

        static void Main(string[] args)
        {
            Application.Init();
            var cssProvider = new CssProvider();
            cssProvider.LoadFromData(@"
                    window {
                        background: #ffffff; /* Plain white background for clarity */
                        color: #5c5c5c; /* Light grey text for general readability, not too harsh on the eyes */
                    }

                    button {
                        background-color: #f7f7f7; /* Very light grey, almost white for button backgrounds */
                        color: #ffffff ; /* Almost black for contrast against the button background */
                        border: 1px solid #e1e1e1; /* Subtle border color to define the buttons */
                        border-radius: 4px; /* Slightly rounded corners for a modern look */
                        font-size: 14px; /* Appropriate font size for legibility */
                        padding: 8px 16px; /* Comfortable padding for button interaction */
                        transition: background-color 0.2s, color 0.2s; /* Smooth transitions for interactive effects */
                        box-shadow: 0 2px 3px rgba(0,0,0,0.03); /* Very light shadow for depth */
                    }

                    button:hover {
                        background-color: #e6e6e6; /* Light grey for hover to indicate interactivity */
                        color: #0c0c0c; /* Slightly darker text on hover to maintain readability */
                    }



            ");
            Gtk.StyleContext.AddProviderForScreen(Gdk.Screen.Default, cssProvider, Gtk.StyleProviderPriority.Application);

            window = new Window("Calculator Assignment");
            window.SetDefaultSize(400, 400);
            grid = new Grid
            {
                ColumnSpacing = 4,
                RowSpacing = 4,
                ColumnHomogeneous = true,
                RowHomogeneous = true
            };

            window.Add(grid);

            entry = new Entry
            {
                IsEditable = false,
                Alignment = 1
            };

            grid.Attach(entry, 0, 0, 5, 1);

            string[,] buttonLabels = {
                {"7","8","9","/","C"},
                {"4","5","6","*","√"},
                {"1","2","3","-","x^2"},
                {".","0","=","+","hist"},
                {"","","","Update","Delete"}
            };

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    int row = i;
                    int column = j;

                    buttons[i, j] = new Button(buttonLabels[i, j])
                    {
                        WidthRequest = 20,
                        HeightRequest = 20
                    };

                    buttons[i, j].Clicked += (sender, e) => Button_Clicked(sender, e, buttonLabels[row, column]);

                    grid.Attach(buttons[i, j], j, i + 1, 1, 1);
                }
            }

            window.SizeAllocated += Window_SizeAllocated;
            window.ShowAll();
            Application.Run();
        }



        static void Window_SizeAllocated(object sender, SizeAllocatedArgs args)
        {
            int fontSize = Math.Min(args.Allocation.Width, args.Allocation.Height) / 10;

            foreach (Widget child in window.Children)
            {
                if (child is Button button)
                {
#pragma warning disable CS0612 // Type or member is obsolete
                    button.ModifyFont(Pango.FontDescription.FromString($"Arial {fontSize}"));
#pragma warning restore CS0612 // Type or member is obsolete
                }
            }
        }
        static void Button_Clicked(object sender, EventArgs e, string buttonText)
        {
            switch (buttonText)
            {
                case "+":
                    lastOperation = Operation.Addition;
                    entry.Text += buttonText;
                    operator1 = "+";
                    break;
                case "-":
                    lastOperation = Operation.Subtraction;
                    entry.Text += buttonText;
                    operator1 = "-";
                    break;
                case "*":
                    lastOperation = Operation.Multiplication;
                    entry.Text += buttonText;
                    operator1 = "*";
                    break;
                case "/":
                    lastOperation = Operation.Division;
                    entry.Text += buttonText;
                    operator1 = "/";
                    break;
                case "√":
                    double sqrtOperand = Evaluate(entry.Text);
                    entry.Text = Math.Sqrt(sqrtOperand).ToString();
                    lastOperation = Operation.SquareRoot;
                    operator1 = "√";
                    SaveCalculations(sqrtOperand, Math.Sqrt(sqrtOperand), operator1);
                    resultShown = true;
                    break;
                case "x^2":
                    double squareOperand = Evaluate(entry.Text);
                    entry.Text = Math.Pow(squareOperand, 2).ToString();
                    lastOperation = Operation.Square;
                    operator1 = "x^2";
                    SaveCalculations(squareOperand, Math.Pow(squareOperand, 2), operator1);
                    resultShown = true;
                    break;
                case "=":
                    operands = ExtractOperands(entry.Text);
                    double result = Evaluate(entry.Text);
                    entry.Text = result.ToString();
                    SaveCalculations(result, result, operator1);
                    resultShown = true;
                    break;
                case "C":
                    entry.Text = "";
                    resultShown = false; 
                    break;
                case "hist":
                    ShowHistoryWindow();
                    break;
                case "Delete":
                    DeleteButton_Clicked();
                    break;
                case "Update":
                    UpdateButton_Clicked();
                    break;
                default:
                    if (resultShown)
                    {
                        entry.Text = buttonText; 
                        resultShown = false; 
                    }
                    else
                    {
                        entry.Text += buttonText; 
                    }
                    break;
            }
        }

        static double Evaluate(string expression)
        {
            try
            {
                return Convert.ToDouble(new System.Data.DataTable().Compute(expression, null));
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error evaluating expression: " + ex.Message);
                return double.NaN;
            }
        }

        private static void DeleteButton_Clicked()
        {
            deleteWindow = new Window("Delete Calculation");
            deleteWindow.SetDefaultSize(300, 100);

            var deleteGrid = new Grid
            {
                ColumnSpacing = 4,
                RowSpacing = 4,
                ColumnHomogeneous = true,
                RowHomogeneous = true
            };
            deleteWindow.Add(deleteGrid);

            var idLabel = new Label("Enter ID:");
            deleteGrid.Attach(idLabel, 0, 0, 1, 1);

            var idEntry = new Entry();
            deleteGrid.Attach(idEntry, 1, 0, 1, 1);

            var confirmButton = new Button("Delete");
            confirmButton.Clicked += (s, args) => ConfirmDelete(idEntry.Text);
            deleteGrid.Attach(confirmButton, 0, 1, 2, 1);

            deleteWindow.ShowAll();
        }

        static void UpdateButton_Clicked()
        {
            var dialog = new Dialog("Update Calculation", window, DialogFlags.Modal | DialogFlags.DestroyWithParent,
                            Gtk.ButtonsType.None); 

            dialog.SetDefaultSize(300, 150);

            var label = new Label("Enter ID of the calculation to update:");
            dialog.ContentArea.Add(label);

            var idEntry = new Entry();
            dialog.ContentArea.Add(idEntry);
            idEntry.SetSizeRequest(200, 30);
            idEntry.CanFocus = true;
            idEntry.GrabFocus();

            var submitButton = new Button("Submit")
            {
                CanDefault = true 
            };
            submitButton.Clicked += (s, args) => OnSubmitClicked(dialog, idEntry.Text);

#pragma warning disable CS0612 // Type or member is obsolete
            dialog.ActionArea.Add(submitButton);
#pragma warning restore CS0612 // Type or member is obsolete

            dialog.ShowAll();
        }

        static void OnSubmitClicked(Dialog dialog, string idText)
        {
            if (int.TryParse(idText, out int id))
            {

                Calculation existingCalculation = GetCalculationByID(id);

                if (existingCalculation != null)
                {
                    UpdateCalculationWindow(existingCalculation);
                }
                else
                {
                    ShowConfirmationMessage($"Calculation with ID {id} does not exist.");
                }
            }
            else
            {
                ShowConfirmationMessage("Invalid ID entered. Please enter a valid integer ID.");
            }

            dialog.Destroy();
        }


    }
}
